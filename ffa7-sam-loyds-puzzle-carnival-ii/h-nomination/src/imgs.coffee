doc = require 'phi.pc/doc'


b = new doc.ImgBuilder __dirname

b.build
	'nomination.png':
		out: 'nomination.jpg'
		density: 200
		htmlDim: '300x'
