doc = require 'phi.pc/doc'

name = 'pony'

b = new doc.ImgBuilder __dirname

imgObj = {}
imgObj["#{name}.png"] =
	out: "#{name}.jpg"
	density: 220
	htmlDim: '320x'

b.build imgObj
