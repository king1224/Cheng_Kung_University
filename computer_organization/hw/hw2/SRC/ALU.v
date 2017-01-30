// ALU

module ALU ( ALUOp,
			 scr1,
			 scr2,
			 shamt,
			 ALU_result,
			 Zero);
	
	parameter bit_size = 32;
	
	input [3:0] ALUOp;
	input [bit_size-1:0] scr1;
	input [bit_size-1:0] scr2;
	input [4:0] shamt;
	
	output [bit_size-1:0] ALU_result;
	output Zero;
	reg [bit_size-1:0] ALU_result;
	reg Zero;
	
	wire [bit_size-1:0] sub_result;
	assign sub_result = scr1 - scr2;
	
	parameter //op_nop = 0,
			  op_add = 1,
			  op_sub = 2,
			  op_and = 3,
			  op_or  = 4,
			  op_xor = 5,
			  op_nor = 6,
			  op_slt = 7,
			  op_sll = 8,
			  op_srl = 9,
			  op_beq = 10,
			  op_bne = 11;
			
	always@ (*) begin
		ALU_result	 = 0;
		Zero		 = 0;
		
		case (ALUOp)
		//implement all operation  
    
 		   op_add : begin ALU_result = scr1 + scr2;
/*$display("addDdddddddd = %h  ERROR, EXPECT Deeeeeeeee= %h ans===== %h ",scr1,scr2,scr1 + scr2);*/ end
		   op_sub : begin ALU_result = scr1 - scr2;
/*$display("subDdddddddd = %h  ERROR, EXPECT Deeeeeeeee= %h ans===== %h ",scr1,scr2,scr1 - scr2);*/ end
		   op_and : begin ALU_result = scr1 & scr2;
/*$display("andDdddddddd = %h  ERROR, EXPECT Deeeeeeeee= %h ans===== %h ",scr1,scr2,scr1 & scr2);*/ end
		   op_or  : begin ALU_result = scr1 | scr2;
/*$display("orDdddddddd = %h  ERROR, EXPECT Deeeeeeeee= %h ans===== %h ",scr1,scr2,scr1 | scr2);*/ end
		   op_xor : begin ALU_result = scr1 ^ scr2;
/*$display("xorDdddddddd = %h  ERROR, EXPECT Deeeeeeeee= %h ans===== %h ",scr1,scr2,scr1 ^ scr2);*/ end
    		   op_nor : begin ALU_result = ~(scr1 | scr2);
/*$display("norDdddddddd = %h  ERROR, EXPECT Deeeeeeeee= %h ans===== %h ",scr1,scr2,~(scr1 | scr2));*/ end
	op_slt : begin ALU_result = (scr1 < scr2)?1:0;
/*$display("sltDdddddddd = %h  ERROR, EXPECT Deeeeeeeee= %h ans===== %h ",scr1,scr2,(scr1 < scr2)?1:0);*/ end
	op_sll : begin ALU_result = scr2 << shamt;
/*$display("sllDdddddddd = %h  ERROR, EXPECT Deeeeeeeee= %h ans===== %h sh=%d",scr1,scr2,scr2 << shamt,shamt);*/ end
	op_srl : begin ALU_result = scr2 >> shamt;
/*$display("srlDdddddddd = %h  ERROR, EXPECT Deeeeeeeee= %h ans===== %h sh=%d",scr1,scr2,scr2 >> shamt,shamt);*/ end
	op_beq : begin Zero = (scr1==scr2)?1:0;
/*$display("beqDdddddddd = %h  ERROR, EXPECT Deeeeeeeee= %h ans===== %h ",scr1,scr2,(scr1==scr2)?1:0);*/ end
	op_bne : begin Zero = (scr1!=scr2)?1:0;
/*$display("bneDdddddddd = %h  ERROR, EXPECT Deeeeeeeee= %h ans===== %h ",scr1,scr2,(scr1!=scr2)?1:0);*/ end
    
		endcase // ALUOp
		
	end

endmodule





