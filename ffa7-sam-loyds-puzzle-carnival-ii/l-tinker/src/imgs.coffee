doc = require 'phi.pc/doc'


b = new doc.ImgBuilder __dirname

b.build
	'tinker.png':
		out: 'tinker.jpg'
		density: 180
		htmlDim: '300x'
