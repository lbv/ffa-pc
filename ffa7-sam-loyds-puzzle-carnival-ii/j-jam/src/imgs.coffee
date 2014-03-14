doc = require 'phi.pc/doc'


b = new doc.ImgBuilder __dirname

b.build
	'jam.png':
		out: 'jam.jpg'
		density: 180
		htmlDim: '300x'
