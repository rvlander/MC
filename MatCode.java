import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcfunctions.MCJFunctions.*;
import org.mc.mcfunctions.MCJOutputArg;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] A=funqui(null,new double[][][]{colon(matrixFromDouble(1),matrixFromDouble(1),matrixFromDouble(5))});

System.out.println("A=");
printMatrix(A);
System.out.println();
}
public static double[][] funqui(MCJOutputArg[] oargs,double[][][] iargs) throws Exception{
double[][] nargin = matrixFromDouble(iargs.length);
double[][] A= new double[0][0];
if(nargin[0][0]>0)A= iargs[0];
double[][] E= new double[0][0];
if(nargin[0][0]>1)E= iargs[1];
double[][] C= new double[0][0];
if(nargin[0][0]>2)C= iargs[2];
double[][] B= new double[0][0];
B=A;
if(any((gt(nargin,matrixFromDouble(1))))){B=add(B,E);
};

if(oargs !=null){
if(oargs.length>0)oargs[0].val=B;
}
return B;
}

}
