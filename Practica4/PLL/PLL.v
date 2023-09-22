module PLL#(
	parameter DATA_WIDTH=8, 
	parameter ADDR_WIDTH=6
) (
	input 	clk50_i,
	input 	rst_ni,
	output [7:0] leds_o
);
	wire clk1_w;
	reg [5:0]counter_w;
	wire we;
	
	assign we = 1'b0;

	// Declare the RAM variable
	reg [DATA_WIDTH-1:0] ram[2**ADDR_WIDTH-1:0];
	
	initial
	begin
		$readmemh ("mem_init.hex",ram);
	end
	
	// Variable to hold the registered read address
	reg [ADDR_WIDTH-1:0] addr_reg;

	always @ (posedge clk1_w)
	begin
		// Write
		if (we)
			ram[counter_w] <= 8'b0;

		addr_reg <= counter_w;
	end

	// Continuous assignment implies read returns NEW data.
	// This is the natural behavior of the TriMatrix memory
	// blocks in Single Port mode.  
	assign q = ram[addr_reg];
	
	/*mipll mipll_u0 (
		.inclk0 (clk50_i),
		.c0	  (clk1_w)
	); */
	
	PLL2 mipll_u0 (
		.clk_i (clk50_i),
		.clk_o	  (clk1_w),
		.rst_ni  (rst_ni)	
	);
	
	
	always @(posedge clk1_w, negedge rst_ni)
	begin
		if(!rst_ni)
			counter_w = 6'b0;
		else
			counter_w = counter_w + 1'b1;
	end

	assign leds_o = counter_w;

endmodule