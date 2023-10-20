module minios (clk_i,rst_ni,leds_o);

	input clk_i;
	input rst_ni;
	output [7:0] leds_o;


miniosII u0 (rst_ni, clk_i);

endmodule 