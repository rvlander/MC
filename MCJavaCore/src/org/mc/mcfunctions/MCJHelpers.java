/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.mc.mcfunctions;

import org.mc.mcjavacore.MCJBaseFunctions;
import org.mc.mcjavacore.MCJElemPosition;
import org.mc.mcjavacore.MCJMatrixDimensionsException;
import org.mc.mcjavautils.MCJUtils;

/**
 *
 * @author rvlander
 */
public class MCJHelpers {

    public static double[] ArrayFromVector(double[][] vect) throws MCJMatrixDimensionsException {
        if (!MCJUtils.isVector(vect)) {
            throw new MCJMatrixDimensionsException();
        }
        int n = (int) MCJBaseFunctions.numel(vect)[0][0];
        double[] res = new double[n];
        for (int i = 1; i <= n; i++) {
            res[i] = MCJUtils.kthElemValue(vect, i);
        }
        return res;
    }

    public static double[][] VectorFromArray(double[] vect, boolean vertical) throws MCJMatrixDimensionsException {
        int n = vect.length;
        double[][] res;
        if (vertical) {
            res = new double[n][1];
        } else {
            res = new double[1][n];
        }
        for (int i = 1; i <= n; i++) {
            MCJElemPosition pos = MCJUtils.kthElemPosition(res, i);
            res[pos.i][pos.j] = vect[i-1];
        }
        return res;
    }
    
    public static MCJOutputArg[] createOutputArgArray(int i){
        MCJOutputArg[] res = new MCJOutputArg[i];
        for(int j=0; j<i; j++){
            res[j] = new MCJOutputArg();
        }
        return res;
    }
}
