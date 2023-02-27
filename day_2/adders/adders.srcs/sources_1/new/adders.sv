`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/25/2023 06:19:18 AM
// Design Name: 
// Module Name: full_adder
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

module full_adder
(
input logic a, b, ci,
output logic sum, co
);
logic wire_1, wire_2;
assign wire_1 = a ^ b; // bitwise XOR
assign wire_2 = wire_1 & ci; // bitwise AND
wire wire_3 = a & b; // bitwise AND
always_comb begin
co = wire_2 | wire_3; // bitwise OR
sum = wire_1 ^ ci ; // bitwise XOR
end
endmodule