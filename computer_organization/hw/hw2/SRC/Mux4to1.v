// Mux4to1

module Mux4to1 ( I0,
				 I1,
				 I2,
				 I3,
				 S,
				 out);

	parameter bit_size = 16;

	input  [bit_size-1:0] I0;
	input  [bit_size-1:0] I1;
	input  [bit_size-1:0] I2;
	input  [bit_size-1:0] I3;
	input  [1:0] S;

	output [bit_size-1:0] out;
	reg [bit_size-1:0] out;
	
  
  //implement Mux4to1 
	always@ (*) begin
	  
		case (S)
    
		2'b00 : begin out=I0; end
		2'b01 : begin out=I1; end
		2'b10 : begin out=I2; end
		2'b11 : begin out=I3; end
    default : begin out=16'b0000000000000000; end
    
		endcase // S
		
	end
	
endmodule





