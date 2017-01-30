// Hazard Detection Unit

module HDU ( // input
			 ID_Rs,
             		 ID_Rt,
			 EX_WR_out,
			 EX_MemtoReg,
			 EX_JumpOP,
			 // output
			 PCWrite,			 
			 IF_IDWrite,
			 IF_Flush,
			 ID_Flush,
			 Branch_Flush,
			 Load_wait
			 );
	
	parameter bit_size = 32;
	
	input [4:0] ID_Rs;
	input [4:0] ID_Rt;
	input [4:0] EX_WR_out;
	input EX_MemtoReg;
	input [1:0] EX_JumpOP;
	
	output PCWrite;
	output IF_IDWrite;
	output IF_Flush;
	output ID_Flush;
	output Branch_Flush;
	output Load_wait;
	reg PCWrite;
	reg IF_IDWrite;
	reg IF_Flush;
	reg ID_Flush;
	reg Branch_Flush;
	reg Load_wait;
	
	always @(*) begin
		//default signal value
		PCWrite		 = 1;
		IF_IDWrite	 = 1;
		IF_Flush	 = 0;
		ID_Flush	 = 0;
		Branch_Flush = 0;
		Load_wait	 = 0;
		
		// Branch
		if ( EX_JumpOP != 2'd0/* write condition - Branch occurs */) begin
			/* write the signal change */
			/* ----------------------- */
			IF_Flush	 = 1;
			ID_Flush	 = 1;
			Branch_Flush 	 = 1;
			/* ----------------------- */
		end
		
		// Load
		if (EX_MemtoReg && ( EX_WR_out==ID_Rs || EX_WR_out==ID_Rt ) && EX_WR_out!=0/* write condition - Load word data hazard occurs */ ) begin
			/* write the signal change */
			/* ----------------------- */
			PCWrite		 = 0;
			IF_IDWrite	 = 0;
			ID_Flush	 = 1;
			Load_wait	 = 1;
			/* ----------------------- */
		end
	end
	
endmodule