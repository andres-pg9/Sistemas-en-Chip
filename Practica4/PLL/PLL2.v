module PLL2(
	input 	clk_i,
	input 	rst_ni,
	
	output reg clk_o
);
	reg [31:0]counter;
	always @(posedge clk_i, negedge rst_ni)
	begin
		if (!rst_ni)
			begin
				counter = 32'b0;
				clk_o = 1'b0;
			end
		else
			begin
				if (counter == 32'd50000000)
					begin
						counter = 32'b0;
						clk_o = ~clk_o;
					end
				else
					counter = counter + 1'b1;
			end
	end

endmodule