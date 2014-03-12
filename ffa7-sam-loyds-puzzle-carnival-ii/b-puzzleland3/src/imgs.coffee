doc = require 'phi.pc/doc'

b = new doc.ImgBuilder __dirname

b.build
	'puzzleland3.png':
		out: 'puzzleland3.jpg'
		density: 140
		htmlDim: '360x'
