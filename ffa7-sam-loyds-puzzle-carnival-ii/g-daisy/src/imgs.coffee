doc = require 'phi.pc/doc'


b = new doc.ImgBuilder __dirname

b.build
	'daisy.png':
		out: 'daisy.jpg'
		density: 200
		htmlDim: '300x'
