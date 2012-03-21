/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.mc.mcjavacore;

import org.mc.mcjavautils.MCJUtils;

/**
 *
 * @author rvlander
 */
public class MCJBaseFunctions {

    public static double[][] matrixFromDouble(double a) {
        double[][] res = {{a}};
        return res;
    }

    public static double[][] numel(double[][] m) {
        double res;
        if (m.length == 0) {
            res = 0;
        } else {
            res = m.length * m[0].length;
        }
        return matrixFromDouble(res);
    }

    public static double[][] size(double[][] m) {
        double[][] res = new double[1][2];
        if (m.length == 0) {
            res[0][0] = 0;
            res[0][1] = 0;
        } else {
            res[0][0] = m.length;
            res[0][1] = m[0].length;
        }
        return res;
    }
    
    public static double[][] duplicate(double[][] m){
        double[][] res = new double[m.length][m[0].length];
        for(int i=0; i<m.length; i++){
            for(int j=0;j<m[0].length;j++)
                res[i][j] = m[i][j];
        }
        return res;
    }

    public static void main(String args[]) {
        double[][] a = new double[7][1];
        MCJUtils.printMatrix(size(a));
    }
    
}
