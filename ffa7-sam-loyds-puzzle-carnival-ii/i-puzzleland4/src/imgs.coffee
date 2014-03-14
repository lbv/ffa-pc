doc = require 'phi.pc/doc'


b = new doc.ImgBuilder __dirname

b.build
	'puzzleland4.png':
		out: 'puzzleland4.jpg'
		density: 200
		# htmlDim: '300x'
