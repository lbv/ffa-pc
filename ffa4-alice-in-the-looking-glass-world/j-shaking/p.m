function y=f(t); y = log(t) * sin(t^(pi/2)); endfunction

X = [0 : 0.001 : 10]

hold on
plot(X, arrayfun(@f, X))
print('p.png', '-dpng', '-S320,240', '-F:7')
