module memoria  #(
	//Constantes
	parameter	ADDR = 32,//Direccion de 32 bits
	parameter	BOFF = $clog2(4),//Tamaño del byte offset (cuántos bytes hay en esa direccion)
	parameter	IDX = 5,//Indice
	parameter	TAG = ADDR - (BOFF + IDX),
	parameter 	DATO = 32
)

(
	//Las entradas siempre son wires, las salidas pueden ser wire o reg
	input					  clk_i,
	input 				  readen_i,
	input 	[ADDR-1:0] addr_i, //Bus de direcciones
	input 	[DATO-1:0] dato_i,
	input 				  writeen_i, 
	
	output 	[DATO-1:0] dato_o,
	output 				  hit_o
);
	//Seccion de declaracion de señales
	wire [IDX-1:0] index;
	wire [TAG-1:0] tag;
	reg  				validmem;
	reg  [TAG-1:0] tagmem;
	reg  [DATO-1:0]datamem;
	reg 				tagvalido;
	
	//Memoria de Bits validos
	reg 	[2**IDX-1:0] 	memoriavalid; //De 31 a 0
	//Memoria de tags
	reg 	[TAG-1:0] 		memoriatag [2**IDX-1:0];
	//Memoria de datos
	reg 	[DATO -1:0] 	memoriadata [2**IDX-1:0];
	
	assign index 	= addr_i[IDX+BOFF-1:BOFF]; //IDX+BOFF-1 = 5 + 2 - 1, [6:2]
	assign tag 		= addr_i[ADDR-1:IDX + BOFF]; //De [31:7]
	
	//Puerto de escritura
	always @(posedge clk_i)
	begin
		if (writeen_i)
			begin
				memoriavalid[index] = 1'b1;
				memoriatag  [index] = tag; //Tag
				memoriadata [index] = dato_i;//Dato de entrada 			
			end
	end
	
	//Puerto de lectura
	always @(*)
	begin
		if (readen_i)
			begin
				validmem = memoriavalid[index];
				tagmem = memoriatag[index];
				datamem = memoriadata[index];
			end
		else
			begin
				validmem = 1'b0;
				tagmem =  {TAG {1'b0}};
				datamem = {DATO {1'b0}};
			end
	end
	
	//Comparacion de Tag
	always @(*)
	begin
		if (tag == tagmem)
			tagvalido = 1'b1;
		else
			tagvalido = 1'b0;
	end
	
	assign hit_o = validmem & tagvalido;
	
	assign dato_o = (hit_o) ? datamem : {DATO {1'b0}};
	
endmodule

