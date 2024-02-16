`timescale 1 ns/10 ps	// counter3b_tb
module counter_tb();
  reg clk=0;
  wire [3:0]cnt;
  always #100  clk=~clk;
  counter i1(.clk(clk),.cnt(cnt));
endmodule

