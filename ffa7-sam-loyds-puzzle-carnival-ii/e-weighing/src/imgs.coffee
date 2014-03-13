doc = require 'phi.pc/doc'


b = new doc.ImgBuilder __dirname

b.build
	'weighing.png':
		out: 'weighing.jpg'
		density: 180
		htmlDim: '350x'
