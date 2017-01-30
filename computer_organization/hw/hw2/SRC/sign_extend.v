// sign_extend

module sign_extend ( in,
					 out);
					 
	input  [15:0] in;
	output [31:0] out;
	/* implement sign_extend */
  	reg [31:0] out;
	// assign out = ;
  	always@ (*)
	begin
		out[31:0]={{16{in[15]}},in[15:0]};
	end
endmodule	
	
	
	
	
	
	
