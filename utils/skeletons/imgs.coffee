doc = require 'phi.pc/doc'


b = new doc.ImgBuilder __dirname

b.build
	'.png':
		out: '.jpg'
		# density: 200
		# htmlDim: '300x'
