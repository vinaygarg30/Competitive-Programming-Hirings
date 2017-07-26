package com.whatfix.codes;
/**
 * @author Vinay
 * Solution to Problem2: https://www.codeeval.com/public_sc/56/
 */
public class RobotMovements {
	public static void main (String[] args)
	{
		int rows=4,cols=5;
		System.out.println(robotPaths(rows,cols));
	}
	
	public static int robotPaths(int rows, int cols) {
    if(rows==0 || cols==0) return 0;
    if(rows==1 || cols==1) return 1;
 
    int[][] dp = new int[rows][cols];
 
    for(int i=0; i<rows; i++){
        dp[i][0] = 1;
    }
 
    for(int j=0; j<cols; j++){
        dp[0][j] = 1;
    }
 
    for(int i=1; i<rows; i++){
        for(int j=1; j<cols; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
 
    return dp[rows-1][cols-1];
    }
}