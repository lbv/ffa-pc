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
.option 'images',
	abbr: 'i'
	flag: true
	help: 'Process images.'


imgDefaults =
	density: 300
	bg: 'white'
	alpha: 'Background'
	jpegSize: '38kb'
	htmlDim: '280x'


class Builder
	constructor: (dir) ->
		@imgs = {}
		@opts = nn.parse()

		@expt = switch @opts.format
			when 'html' then new expts.Html
			when 'latex' then new expts.Latex

		buildImg = switch @opts.format
			when 'html' then path.normalize "#{dir}/../build/html"
			when 'latex' then path.normalize "#{dir}/../build/img/latex"

		@path =
			buildImg: buildImg
			img: path.normalize "#{dir}/../img"

	addImages: (imgs) ->
		for img, obj of imgs
			imgs[img] = _.defaults obj, imgDefaults

		@imgs = _.extend @imgs, imgs

	constraints: (constr...) ->
		@expt.constraints constr...

	figureRight: (title, href, size, lines) ->
		@expt.figureRight title, href, size, lines

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

	makeImages: ->
		@makeImage src, img for src, img of @imgs

	samples: (input, output) ->
		@expt.samples input, output

	set: (@text) ->

	run: ->
		if @opts.images
			@makeImages()
			return

		puts @text

module.exports = { Builder }
