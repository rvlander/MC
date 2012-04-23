/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.mc.mcfunctions;

import org.mc.mcjavacore.MCJBaseFunctions;

/**
 *
 * @author rvlander
 */
public class MCJFunctions {

    public static double[][] numel(MCJOutputArg[] out_args, double[][][] in_args) {
        double[][] arg = in_args[0];
        double[][] res = MCJBaseFunctions.numel(arg);
        if (out_args != null) {
            if (out_args.length == 1) {
                out_args[0].val = res;
            }
        }
        return res;
    }

    public static double[][] size(MCJOutputArg[] oargs, double[][][] iargs) {
        double[][] nargin = MCJBaseFunctions.matrixFromDouble(iargs.length);
        double[][] A = new double[0][0];
        if (nargin[0][0] > 0) {
            A = iargs[0];
        }
        double[][] res = MCJBaseFunctions.size(A);
        double[][] dim = new double[0][0];
        if(iargs.length == 2){
            res = MCJBaseFunctions.matrixFromDouble(res[0][(int)iargs[1][0][0]-1]);
        }

        if (oargs != null) {
            if (oargs.length == 1) {
                oargs[0].val = res;
            }
            if (oargs.length == 2) {
                oargs[0].val = MCJBaseFunctions.matrixFromDouble(res[0][0]);
                oargs[1].val = MCJBaseFunctions.matrixFromDouble(res[0][1]);
            }
        }
        
        return res;
    }
}
