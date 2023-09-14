module sumador (
	//Seccion de puertos de entrada
	input A,
	input B,
	input Cin,
	//Seccion de puertos de salida
	output S,
	output Cout
);
	//Señales intermedias
	wire xor1_o;
	wire and1_o;
	wire and2_o;
	
	//Descripcion de la compuerto XOR 1
	assign xor1_o = A ^ B;
	
	//Descripción de la compuerta AND 1
	assign and1_o = A & B;
	
	//Descripción de la compuerta AND 2
	assign and2_o = xor1_o & Cin;
	
	//Descripción de la compuerta XOR 2 - Resultado del sumador
	assign S = xor1_o ^ Cin;
	
	//Descripción de la compuerta OR - Acarreo de salida del sumador
	assign Cout = and1_o | and2_o;
		
endmodule