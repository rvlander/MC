/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.mc.mcjavacore;

/**
 *
 * @author rvlander
 */
class MCJCMatrixDimensionsExceptions extends Exception {

    public MCJCMatrixDimensionsExceptions() {
        System.err.println("Matrix dimensions must agree");
    }
    
}
