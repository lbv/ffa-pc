doc = require 'phi.pc/doc'


b = new doc.ImgBuilder __dirname

b.build
	'disputed.png':
		out: 'disputed.jpg'
		density: 250
		# htmlDim: '300x'
