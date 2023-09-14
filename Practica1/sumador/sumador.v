module sumador (
	input 		clk,
	input [3:0] A,
	input [3:0] B,
	input 		Cin,
	output [3:0] S,
	output		Cout
);	
	reg [3:0] A1;
	reg [3:0] B1;
	reg 		 Cin1;
	
	wire[3:0] S;
	wire 		 Cout;

	//Registrar entradas
	always @(posedge clk)
	begin
		A1 <= A;
		B1 <= B;
		Cin1 <= Cin;
	end
	
	
	wire cout0;
	wire cout1;
	wire cout2;
	
	sumador1 FA0 (A1[0], B1[0], Cin1, S[0], cout0);
	sumador1 FA1 (A1[1], B1[1], cout0, S[1], cout1);
	sumador1 FA2 (A1[2], B1[2], cout1, S[2], cout2);
	sumador1 FA3 (A1[3], B1[3], cout2, S[3], Cout);
	
	//Registrar salidas
	always @(posedge clk)
	begin
		S1 <= S
		Cout1 <= Cout;
	end
		


endmodule