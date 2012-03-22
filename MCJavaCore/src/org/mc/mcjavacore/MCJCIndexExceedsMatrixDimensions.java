/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.mc.mcjavacore;

/**
 *
 * @author rvlander
 */
public class MCJCIndexExceedsMatrixDimensions extends Exception {

    public MCJCIndexExceedsMatrixDimensions() {
        System.err.println("Index exceeds matrix dimensions");
    }
    
}
