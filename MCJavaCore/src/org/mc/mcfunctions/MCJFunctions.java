/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.mc.mcfunctions;

import org.mc.mcjavacore.MCJBaseFunctions;
import org.mc.mcjavacore.MCJElemPosition;
import org.mc.mcjavacore.MCJMatrixDimensionsException;
import org.mc.mcjavacore.MCJOperators;
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
    public static double[][] any(MCJOutputArg[] out_args, double[][][] in_args) {
        double[][] arg = in_args[0];
        boolean bres = MCJUtils.any(arg);
        double[][] res;
        if(bres){
            res= MCJBaseFunctions.matrixFromDouble(1);
        }else {
            res= MCJBaseFunctions.matrixFromDouble(0);
        }
        if (out_args != null) {
            if (out_args.length == 1) {
                out_args[0].val = res;
            }
        }
        return res;
    }
    
    public static double[][] all(MCJOutputArg[] out_args, double[][][] in_args) {
        double[][] arg = in_args[0];
        boolean bres = MCJUtils.all(arg);
        double[][] res;
        if(bres){
            res= MCJBaseFunctions.matrixFromDouble(1);
        }else {
            res= MCJBaseFunctions.matrixFromDouble(0);
        }
        if (out_args != null) {
            if (out_args.length == 1) {
                out_args[0].val = res;
            }
        }
        return res;
    }
    
    public static double[][] mod(MCJOutputArg[] out_args, double[][][] in_args) throws MCJMatrixDimensionsException {
        double[][] a = in_args[0];
        double[][] b = in_args[1];
        double[][] res = MCJOperators.mod(a, b);
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
        if (iargs.length == 2) {
            res = MCJBaseFunctions.matrixFromDouble(res[0][(int) iargs[1][0][0] - 1]);
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
        if (MCJBaseFunctions.numel(arg)[0][0] != 0) {
            int m = arg.length;
            int n = arg[0].length;
            res = new double[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    res[i][j] = Math.sqrt(arg[i][j]);
                }
            }

        } else {
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
        if (MCJBaseFunctions.numel(arg)[0][0] != 0) {
            int m = arg.length;
            int n = arg[0].length;
            res = new double[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    res[i][j] = Math.abs(arg[i][j]);
                }
            }

        } else {
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
        if (MCJBaseFunctions.numel(arg)[0][0] != 0) {
            int m = arg.length;
            int n = arg[0].length;
            res = new double[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    res[i][j] = Math.sin(arg[i][j]);
                }
            }

        } else {
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
        if (MCJBaseFunctions.numel(arg)[0][0] != 0) {
            int m = arg.length;
            int n = arg[0].length;
            res = new double[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    res[i][j] = Math.signum(arg[i][j]);
                }
            }

        } else {
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


        int m, n;

        if (nargin >= 2) {
            m = (int) iargs[0][0][0];
            n = (int) iargs[1][0][0];
        } else {
            if (MCJBaseFunctions.numel(iargs[0])[0][0] == 2) {
                m = (int) MCJUtils.kthElemValue(iargs[0], 1);
                n = (int) MCJUtils.kthElemValue(iargs[0], 2);
            } else {
                m = (int) MCJUtils.kthElemValue(iargs[0], 1);
                n = m;
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
        int k = (int) MCJBaseFunctions.numel(arg)[0][0];


        int nargin = iargs.length;
        if (nargin >= 2) {
            k = (int) iargs[1][0][0];
        }


        double[] inter_res = new double[k];
        int nb_nz = 0;
        int i = 0;

        while (nb_nz < k && i < (int) MCJBaseFunctions.numel(arg)[0][0]) {
            if (MCJUtils.kthElemValue(arg, i + 1) != 0) {
                inter_res[nb_nz] = i + 1;
                nb_nz++;
            }
            i++;
        }




        double[][] res = new double[1][nb_nz];
        System.arraycopy(inter_res, 0, res[0], 0, nb_nz);






        if (oargs != null) {
            if (oargs.length == 1) {
                oargs[0].val = res;
            } else if (oargs.length == 2) {
                double[][] I = new double[1][nb_nz];
                double[][] J = new double[1][nb_nz];
                for (i = 0; i < nb_nz; i++) {
                    MCJElemPosition ind = MCJUtils.kthElemPosition(arg, (int) inter_res[i]);
                    I[0][i] = ind.i + 1;
                    J[0][i] = ind.j + 1;
                }
                oargs[0].val = I;
                oargs[1].val = J;
            }
        }
        return res;
    }

    public static double[][] sum(MCJOutputArg[] oargs, double[][][] iargs) {
        double[][] nargin = MCJBaseFunctions.matrixFromDouble(iargs.length);
        double[][] A = iargs[0];
        if (nargin[0][0] > 0) {
            A = iargs[0];
        }

        double[][] res;


        if (MCJUtils.isVector(A)) {
            double somme = 0;
            for (int i = 1; i <= MCJBaseFunctions.numel(A)[0][0]; i++) {
                somme += MCJUtils.kthElemValue(A, i);
            }
            res = MCJBaseFunctions.matrixFromDouble(somme);
        } else {
            int m = A.length;
            int n = A[0].length;
            res = new double[1][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    res[0][i] += A[j][i];
                }
            }
        }

        double[][] dim = new double[0][0];
        if (iargs.length == 2) {
            res = MCJBaseFunctions.matrixFromDouble(res[0][(int) iargs[1][0][0] - 1]);
        }

        if (oargs != null) {
            if (oargs.length == 1) {
                oargs[0].val = res;
            }
        }

        return res;
    }
    
    
    public static double[][] max(MCJOutputArg[] oargs, double[][][] iargs) {
        double[][] nargin = MCJBaseFunctions.matrixFromDouble(iargs.length);
        double[][] A = iargs[0];
        if (nargin[0][0] > 0) {
            A = iargs[0];
        }

        double[][] res;
        double[][] ind;


        if (MCJUtils.isVector(A)) {
            double calc_max = Double.MIN_VALUE;
            double indi =1;
            for (int i = 1; i <= MCJBaseFunctions.numel(A)[0][0]; i++) {
                double val = MCJUtils.kthElemValue(A, i);
                if(val>calc_max){
                    indi = i;
                    calc_max = val;
                };
            }
            res = MCJBaseFunctions.matrixFromDouble(calc_max);
            ind = MCJBaseFunctions.matrixFromDouble(indi);
        } else {
            int m = A.length;
            int n = A[0].length;
            res = new double[1][n];
            ind = new double[1][n];
            for (int i = 0; i < n; i++) {
                res[0][i] = Double.MIN_VALUE;
                ind[0][i] = 1;
                for (int j = 0; j < m; j++) {
                    if(res[0][i] < A[j][i]){
                        res[0][i] = A[j][i];
                        ind[0][i] = j+1;
                    };
                }
            }
        }

        

        if (oargs != null) {
            if (oargs.length > 0) {
                oargs[0].val = res;
            }
            if (oargs.length > 1) {
                oargs[1].val = ind;
            }
        }

        return res;
    }

    public static double[][] message(MCJOutputArg[] oargs, double[][][] iargs) {
        double[][] nargin = MCJBaseFunctions.matrixFromDouble(iargs.length);
        double[][] A = iargs[0];

        double[][] res = A;

        if (oargs != null) {
            if (oargs.length == 1) {
                oargs[0].val = res;
            }
        }

        return res;
    }
    
    public static double[][] error(MCJOutputArg[] oargs, double[][][] iargs) throws Exception {
        double[][] nargin = MCJBaseFunctions.matrixFromDouble(iargs.length);
        double[][] A = iargs[0];

        throw new Exception("Matlab error : " + MCJBaseFunctions.stringFromMatrix(A));
    }
}
