doc = require 'phi.pc/doc'


b = new doc.ImgBuilder __dirname

b.build
	'courier.png':
		out: 'courier.jpg'
		density: 200
