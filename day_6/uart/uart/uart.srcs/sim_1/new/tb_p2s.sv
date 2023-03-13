`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/11/2023 06:56:50 AM
// Design Name: 
// Module Name: tb_p2s
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module tb_p2s;

  timeunit       1ns;
  timeprecision  1ps;

logic clk =0, rstn = 0;
localparam CLK_PERIOD = 10;

initial forever
    #(CLK_PERIOD/2)
    clk <= ~clk;


logic s_ready, p_valid=0, p_ready, s_data, s_valid;
parameter N = 8;
logic [N-1:0] p_data;

 P2S #(.N(N)) dut(.*);

initial begin 

$dumpfile("dump.vcd"); $dumpvars;

@(posedge clk)  #1  rstn <= 1;
@(posedge clk) #1 p_data  <= 8'd7; p_valid <= 0; s_ready <= 1;  
@(posedge clk) #1 p_data <=8'd100; p_valid <=1; s_ready<=1;
@(posedge clk) #1 p_valid <= 0;



end 

endmodule
