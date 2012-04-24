/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.mc.mcfunctions;

import org.mc.mcjavacore.MCJBaseFunctions;
import org.mc.mcjavacore.MCJElemPosition;
import org.mc.mcjavautils.MCJUtils;

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
    
    public static double[][] sqrt(MCJOutputArg[] oargs, double[][][] iargs) {
        double[][] arg = iargs[0];
        double[][] res;
        if(MCJBaseFunctions.numel(arg)[0][0]!=0){
            int m = arg.length; int n = arg[0].length; 
            res = new double[m][n];
            for(int i=0;i<m;i++){
                for (int j =0;j<n;j++){
                    res[i][j] = Math.sqrt(arg[i][j]);
                }
            }
            
        }else {
            res = new double[0][0];
        }
        
        
        if (oargs != null) {
            if (oargs.length == 1) {
                oargs[0].val = res;
            }
        }
        return res;
    }
    
    public static double[][] abs(MCJOutputArg[] oargs, double[][][] iargs) {
        double[][] arg = iargs[0];
        double[][] res;
        if(MCJBaseFunctions.numel(arg)[0][0]!=0){
            int m = arg.length; int n = arg[0].length; 
            res = new double[m][n];
            for(int i=0;i<m;i++){
                for (int j =0;j<n;j++){
                    res[i][j] = Math.abs(arg[i][j]);
                }
            }
            
        }else {
            res = new double[0][0];
        }
        
        
        if (oargs != null) {
            if (oargs.length == 1) {
                oargs[0].val = res;
            }
        }
        return res;
    }
    
    public static double[][] sin(MCJOutputArg[] oargs, double[][][] iargs) {
        double[][] arg = iargs[0];
        double[][] res;
        if(MCJBaseFunctions.numel(arg)[0][0]!=0){
            int m = arg.length; int n = arg[0].length; 
            res = new double[m][n];
            for(int i=0;i<m;i++){
                for (int j =0;j<n;j++){
                    res[i][j] = Math.sin(arg[i][j]);
                }
            }
            
        }else {
            res = new double[0][0];
        }
        
        
        if (oargs != null) {
            if (oargs.length == 1) {
                oargs[0].val = res;
            }
        }
        return res;
    }
    
    public static double[][] sign(MCJOutputArg[] oargs, double[][][] iargs) {
        double[][] arg = iargs[0];
        double[][] res;
        if(MCJBaseFunctions.numel(arg)[0][0]!=0){
            int m = arg.length; int n = arg[0].length; 
            res = new double[m][n];
            for(int i=0;i<m;i++){
                for (int j =0;j<n;j++){
                    res[i][j] = Math.signum(arg[i][j]);
                }
            }
            
        }else {
            res = new double[0][0];
        }
        
        
        if (oargs != null) {
            if (oargs.length == 1) {
                oargs[0].val = res;
            }
        }
        return res;
    }
    
    public static double[][] zeros(MCJOutputArg[] oargs, double[][][] iargs) {
        double[][] arg = iargs[0];
        
        int nargin = iargs.length;
        
        
        int m,n;
        
        if(nargin >=2){
            m = (int)iargs[0][0][0];
            n = (int)iargs[1][0][0];
        }else{
            if(MCJBaseFunctions.numel(iargs[0])[0][0] ==2){
                m = (int)MCJUtils.kthElemValue(iargs[0],1);
                n = (int)MCJUtils.kthElemValue(iargs[0],2);
            }else {
                m=(int)MCJUtils.kthElemValue(iargs[0],1);
                n=m;
            }
        }
        
        
        double[][] res = new double[m][n];
        
        
        
        
        if (oargs != null) {
            if (oargs.length == 1) {
                oargs[0].val = res;
            }
        }
        return res;
    }
    
    public static double[][] find(MCJOutputArg[] oargs, double[][][] iargs) {
        double[][] arg = iargs[0];
        int k = (int)MCJBaseFunctions.numel(arg)[0][0];
        
        
        int nargin = iargs.length;
        if(nargin>=2){
            k = (int)iargs[1][0][0];
        }
        
        
        double[] inter_res = new double[k];
        int nb_nz=0;
        int i=0;
        
        while(nb_nz<k && i<(int)MCJBaseFunctions.numel(arg)[0][0]){
            if(MCJUtils.kthElemValue(arg, i+1) != 0){
                inter_res[nb_nz] = i+1;
                nb_nz++;
            }
            i++;
        }
        
        
     
        
        double[][] res = new double[1][nb_nz];
        System.arraycopy(inter_res, 0, res[0], 0, nb_nz);
        
        
        
        
        
        
        if (oargs != null) {
            if (oargs.length == 1) {
                oargs[0].val = res;
            }else  if (oargs.length == 2) {
                double[][] I = new double[1][nb_nz];
                double[][] J = new double[1][nb_nz];
                for(i=0;i<nb_nz;i++){
                    MCJElemPosition ind = MCJUtils.kthElemPosition(arg, (int)inter_res[i]);
                    I[0][i] = ind.i+1;
                    J[0][i] = ind.j+1; 
                }
                oargs[0].val = I;
                oargs[1].val = J;
            }
        }
        return res;
    }
}
