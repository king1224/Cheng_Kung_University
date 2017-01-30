// Mux2to1

module Mux2to1 ( I0,
				 I1,
				 S,
				 out);

	parameter bit_size = 16;

	input  [bit_size-1:0] I0;
	input  [bit_size-1:0] I1;
	input  S;

	output [bit_size-1:0] out;
  	reg [bit_size-1:0] out;
	/* implement Mux2to1 */
	// assign out =  ;
	always@ (*) begin
		case (S)
    
		1'b0 : begin out=I0; end
		1'b1 : begin out=I1; end
    default : begin out=16'b0000000000000000; end
    
		endcase // S
	end
endmodule





