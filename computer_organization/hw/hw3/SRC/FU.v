// Forwarding Unit

module FU ( // input 
			EX_Rs,
            EX_Rt,
			M_RegWrite,
			M_WR_out,
			WB_RegWrite,
			WB_WR_out,
			// output
			enF1,
			enF2,
			sF1,
			sF2	
			);

	input [4:0] EX_Rs;
    	input [4:0] EX_Rt;
    	input M_RegWrite;
    	input [4:0] M_WR_out;
    	input WB_RegWrite;
    	input [4:0] WB_WR_out;

	output enF1;
    	output enF2;
    	output sF1;
    	output sF2;
	
	reg enF1;
	reg enF2;
	reg sF1;
	reg sF2;

	always @(*) begin
			enF1=0;
			enF2=0;
		// Rs Forwarding
		/* determine sF1 & enF1 by input signals*/
		/* ----------------------- */
		if(M_RegWrite && EX_Rs!=0 && EX_Rs==M_WR_out)
		begin
			enF1=1;
			sF1 =0;
		end
		if(WB_RegWrite && EX_Rs!=0 && EX_Rs!=M_WR_out && EX_Rs==WB_WR_out)
		begin
			enF1=1;
			sF1 =1;
		end
		/* ----------------------- */
		
		// Rt Forwarding
		/* determine sF2 & enF2 by input signals*/
		/* ----------------------- */
		if(M_RegWrite && EX_Rt!=0 && EX_Rt==M_WR_out)
		begin
			enF2=1;
			sF2 =0;
		end
		if(WB_RegWrite && EX_Rt!=0 && EX_Rt!=M_WR_out && EX_Rt==WB_WR_out)
		begin
			enF2=1;
			sF2 =1;
		end
		/* ----------------------- */
//$display("FU=%b    %b      sF2= %b       %b\n",enF1,enF2,sF1,sF2);
//$display("MatchRs=%d    Rt=%d     %d      %d\n",EX_Rs,EX_Rt,M_WR_out,WB_WR_out);
	end
	
endmodule







