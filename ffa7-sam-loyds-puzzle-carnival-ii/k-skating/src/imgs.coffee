doc = require 'phi.pc/doc'


b = new doc.ImgBuilder __dirname

b.build
	'skating.png':
		out: 'skating.jpg'
		density: 190
		htmlDim: '300x'
