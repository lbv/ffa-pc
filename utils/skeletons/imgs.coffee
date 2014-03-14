doc = require 'phi.pc/doc'

name = ''

b = new doc.ImgBuilder __dirname

imgObj = {}
imgObj["#{name}.png"] =
	out: "#{name}.jpg"
	# density: 200
	# htmlDim: '300x'

b.build imgObj
