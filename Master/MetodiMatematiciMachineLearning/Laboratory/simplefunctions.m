% (1 - cos(x)) / x^2
x = linspace(10^-4,10*pi);
y = (1 - cos(x)) ./(x.^2);
figure(1);subplot(2,2,1);plot(x,y)

% (e^x - 1) / x
x1 = linspace(10^-4,1);
y1 = (exp(x1) - 1)./x1;
subplot(2,2,2);plot(x1,y1)

% xlog(x)
x2 = linspace(10e-4,1);
y2 = x2.*log(x2);
subplot(2,2,3);plot(x2,y2)

% (1 + 1/n)^n
n = linspace(1,200);
y3 = (1 + (1./n)).^n;
subplot(2,2,4);plot(n,y3)