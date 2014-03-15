_ = require 'underscore'
nn = require 'nomnom'
path = require 'path'
sh = require 'shelljs'
util = require 'util'

expts = require './exporters'


{ puts } = util


nn
.option 'format',
	abbr: 'f'
	choices: [ 'html', 'latex' ]
	required: true
	help: 'Format to export to (html, latex).'


class DocBuilder
	constructor: ->
		@opts = nn.parse()

		@expt = switch @opts.format
			when 'html' then new expts.Html
			when 'latex' then new expts.Latex

	build: (text) ->
		puts text

	constraints: (constr...) ->
		@expt.constraints constr...

	figureRight: (title, href, size, lines) ->
		@expt.figureRight title, href, size, lines

	moreInfo: (url) ->
		@expt.moreInfo url

	samples: (input, output) ->
		@expt.samples input, output


imgDefaults =
	density: 300
	bg: 'white'
	alpha: 'Background'
	jpegSize: '38kb'
	htmlDim: '280x'

class ImgBuilder
	constructor: (dir) ->
		nn.option 'img',
			position: 0
			required: true
			help: 'path to the image'

		@opts = nn.parse()

		buildImg = switch @opts.format
			when 'html' then path.normalize "#{dir}/../build/html"
			when 'latex' then path.normalize "#{dir}/../build/img/latex"

		@path =
			buildImg: buildImg
			img: path.normalize "#{dir}/../img"

	build: (imgs) ->
		for img, obj of imgs
			imgs[img] = _.defaults obj, imgDefaults

		@makeImage @opts.img, imgs[@opts.img] if imgs[@opts.img]?


	makeImage: (src, img) ->
		dirOut = @path.buildImg

		pathIn = "#{@path.img}/#{src}"
		pathOut = "#{dirOut}/#{img.out}"

		unless sh.test '-f', pathIn
			console.error "File #{pathIn} not found"
			return

		sh.mkdir '-p', dirOut

		inArgs = ""
		outArgs = ""

		outArgs += " -background #{img.bg}" if img.bg
		outArgs += " -alpha #{img.alpha}" if img.alpha

		if img.out.substr(-4) is '.jpg'
			outArgs += " -define jpeg:extent=#{img.jpegSize}"

		if @opts.format is 'latex'
			inArgs += " -density #{img.density} -units PixelsPerInch"

		if @opts.format is 'html'
			outArgs += " -resize #{img.htmlDim}"

		console.log "Building #{img.out}"
		sh.exec "convert #{inArgs} #{pathIn} #{outArgs} #{pathOut}"

		puts "Original image:"
		sh.exec "du -sh #{pathIn}"
		puts "Image for #{@opts.format}"
		sh.exec "du -sh #{pathOut}"


module.exports = { DocBuilder, ImgBuilder }
