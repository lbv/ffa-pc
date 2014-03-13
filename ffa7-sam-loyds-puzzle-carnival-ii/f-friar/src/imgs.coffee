doc = require 'phi.pc/doc'


b = new doc.ImgBuilder __dirname

b.build
	'friar.png':
		out: 'friar.jpg'
		density: 180
