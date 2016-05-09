package de.fosd.jdime.Similarity;

import de.fosd.jdime.util.IOFunctionSet;
import org.rosuda.JRI.REXP;
import org.rosuda.JRI.Rengine;

import java.io.IOException;

/**
 * Created by shuruiz on 5/8/16.
 */
public class StringSimilarity {
    public void calculateStringSimilarity(String projectPath, String repo, int dirNum, Rengine re) {
        String testDir = projectPath + repo;
        String sourcecodeDir = testDir + "/" + repo;
        String analysisDir = testDir + "/DPGraph/" + dirNum + "/";
        String strList = "";
        IOFunctionSet iof = new IOFunctionSet();
        try {
            strList = iof.readResult(analysisDir + "/StringList.txt");
        } catch (IOException e) {
            e.printStackTrace();
        }

        int lastComma = strList.lastIndexOf(",");
        strList = strList.substring(0, lastComma);
        re.eval("str<- c(" + strList + ")");
        re.eval(" d  <- adist(str)");
        re.eval("rownames(d) <- str");
        re.eval("matrix<-as.dist(d)");
        re.eval("hc <- hclust(as.dist(d))");
        for(int i=2;i<=10;i++) {
             re.eval("df <- data.frame(str,cutree(hc,k="+i+"))");
            REXP cluster_R = re.eval("df$cutree.hc..k..."+i+".");
            int[] cluster = cluster_R.asIntArray();
        }

    }
}
