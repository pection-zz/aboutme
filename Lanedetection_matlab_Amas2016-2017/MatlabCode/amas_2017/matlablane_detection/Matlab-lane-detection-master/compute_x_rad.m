function [x] = compute_x_rad ( y, rho, theta )

x = ( rho - y * sin(theta) ) / ( cos(theta));