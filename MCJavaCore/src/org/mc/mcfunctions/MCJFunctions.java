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
    public static double[][] numel(MCJOutputArg[] out_args, double[][][] in_args){
        double[][] arg = in_args[0];
        double[][] res = MCJBaseFunctions.numel(arg);
        if(out_args!= null){
            if(out_args.length == 1){
                out_args[0].val = res;
            }
            else if(out_args.length>1){
                out_args[0].val = MCJBaseFunctions.matrixFromDouble(res[0][0]);
                out_args[1].val = MCJBaseFunctions.matrixFromDouble(7);
            }
        }
        return res;
    }
    
}
