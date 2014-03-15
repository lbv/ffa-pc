_ = require 'underscore'


class Exporter
	constraints: (constr...) ->
		constr = ("$#{c}$" for c in constr).join '\\ \\ ; \\ \\ '
		"\\ \\ \\  #{constr}"

class Html extends Exporter
	figureRight: (title, href) ->
		"""
		<div class="ffa-figure-right">
		  <img src="#{href}" alt="#{_.escape title}"/>
		  <p class="caption">#{_.escape title}</p>
		</div>
		"""

	moreInfo: (url) ->
		"""
		<div class="ffa-more-info">
		Side note: for more information about this contest, please visit
		<a href="#{url}">this website</a>.
		</div>
		"""

	samples: (input, output) ->
		"""
		<table class="table-io">
		  <tr>
		    <th>Sample Input</th>
		    <th>Output for Sample Input</th>
		  </tr>
		  <tr>
		    <td>
		      <pre>#{input}</pre>
		    </td>
		    <td>
		      <pre>#{output}</pre>
		    </td>
		  </tr>
		</table>
		"""

class Latex extends Exporter
	figureRight: (title, href, size, lines) ->
		lineHeight = if lines? then "[#{lines}]" else ''

		"""
		\\begin{wrapfigure}#{lineHeight}{r}{#{size}\\textwidth}
		  \\begin{minipage}[t]{#{size}\\textwidth}
		    \\centering
		    \\vspace{0pt}
		    \\includegraphics{#{href}}
		    \\\\ \\footnotesize #{title}
		  \\end{minipage}
		\\end{wrapfigure}
		"""

	moreInfo: (url) -> ''

	samples: (input, output) ->
		"""
		\\paragraph{}
		\\vspace{-20pt}
		\\noindent
		\\begin{tabular}{|l|l|}
		  \\hline
		  \\FFATitle{Sample Input} &
		  \\FFATitle{Output for Sample Input} \\\\
		  \\hline
		  \\begin{minipage}[t]{0.48\\textwidth}
		    \\vspace{-8pt}
		    \\begin{verbatim}#{input}\\end{verbatim}
		    \\vspace{-4pt}
		  \\end{minipage} &
		  \\begin{minipage}[t]{0.48\\textwidth}
		    \\vspace{-8pt}
		    \\begin{verbatim}#{output}\\end{verbatim}
		    \\vspace{-4pt}
		  \\end{minipage} \\\\
		  \\hline
		\\end{tabular}
		"""



module.exports = { Html, Latex }
