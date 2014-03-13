path = require 'path'
sh = require 'shelljs'
spawn = require('child_process').spawn


DIR_SKEL = path.normalize "#{__dirname}/../../skeletons"


err = (msg) ->
	console.error msg
	sh.exit 1


module.exports =
	contest: ->
		option '-d', '--dir [string]', 'Directory for the problem'

		task 'skel', 'Create new problem, copying skeleton files', (opt) ->
			err 'Directory required' unless opt.dir?
			err "#{opt.dir} already exists" if sh.test '-d', opt.dir

			console.log "Creating #{opt.dir}..."
			sh.mkdir '-p', opt.dir

			dir_img = "#{opt.dir}/img"
			dir_prg = "#{opt.dir}/prg"
			dir_src = "#{opt.dir}/src"
			name = opt.dir.substr 2

			sh.cp "#{DIR_SKEL}/Tupskel", "#{opt.dir}/Tupfile"
			sh.cp "#{DIR_SKEL}/Cakefile", opt.dir

			sh.mkdir '-p', dir_src
			sh.cp "#{DIR_SKEL}/problem.coffee", "#{dir_src}/#{name}.coffee"
			sh.cp "#{DIR_SKEL}/imgs.coffee", dir_src

			sh.mkdir '-p', dir_img

			sh.mkdir '-p', dir_prg
			sh.cp '-r', "#{DIR_SKEL}/prg", opt.dir
			sh.mv "#{dir_prg}/problem.cpp", "#{dir_prg}/#{name}.cpp"

	problem: (doc) ->
		task 'spell', 'Check spelling of document', ->
			console.log "Checking spell of #{doc}.."
			path_dict = '../spell-dict'
			path_doc = "./build/latex/#{doc}.embed.tex"

			spawn 'aspell', [ '-p', path_dict, '-d', 'en', '-c', path_doc ],
				{ stdio: 'inherit' }
