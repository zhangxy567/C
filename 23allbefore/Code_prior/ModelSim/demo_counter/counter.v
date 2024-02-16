module counter(clk,cnt);	//counter3b.v
  input clk;
  output reg[3:0]cnt=4'b0;
  always @(posedge clk) begin
    cnt<=cnt+1;
  end
endmodule

