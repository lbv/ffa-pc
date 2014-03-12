doc = require 'phi.pc/doc'


b = new doc.ImgBuilder __dirname


b.build
	'archery.png':
		out: 'archery.jpg'
		density: 190
