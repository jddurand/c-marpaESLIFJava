// We do not want to rely on com.sun.jna.Platform not available everywhere.
// Although this is not perfect, we assume the following is reliable enough.

public class Is64 {
    public static void main(String[] args) {
	boolean is64 = false;

	String sunArchDataModel = System.getProperty("sun.arch.data.model");
	if (sunArchDataModel != null) {
	    is64 = "64".equals(sunArchDataModel);
	} else {
	    String javaVmName = System.getProperty("java.vm.name");
	    if(javaVmName != null) {
		is64 = javaVmName.contains("64");
	    }
	}

	System.out.print(is64 ? "64" : "32");
    }
}
