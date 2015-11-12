        
ArrayList<String> inputFilePaths = new ArrayList<>();
        String result = "";
        String outputPath = "testcpp/mergedRepo/3-wayMerge/upstream";

        String filePath = path + fork + "/Marlin/Marlin/" + mergedFile;
        File f = new File(filePath);

        String upstreamOldPath = "testcpp/upstreamVar/" + fork+"Upstream/Marlin/Marlin/";
        File f1 = new File(upstreamOldPath+mergedFile);

        if (f.exists()) {
            inputFilePaths.add(fork + "/Marlin/Marlin/+" + fork);
            outputPath += "_" + fork;

            if (f1.exists()) {
                outputPath += "_oldUpstream";;
            } else {
                System.out.println(upstreamOldPath + " not exist!");
                outputPath += "_no_oldUpstream";
            }

        } else {
            System.out.println(filePath + " not exist!");
            outputPath += "_no_" + fork;
            if (f1.exists()) {
                outputPath += "_oldUpstream";

            } else {
                System.out.println(upstreamOldPath + " not exist!");
                outputPath += "_no_oldUpstream";

                try {
                    String statisticsPath = "testcpp/statistics/result.txt";
                    String upstreamNEW = readResult("testcpp/originMarlin/upstream/Marlin/Marlin/"+mergedFile);
                    IOFunctionSet ioFunctionSet = new IOFunctionSet();
                    ioFunctionSet.writeTofile("upstream(NEW) UNIQUE FILE : " + mergedFile + " ,LOC: " + upstreamNEW.split("\n").length+1+ "\n", statisticsPath);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }


        outputPath+="/"+mergedFile;

        if (inputFilePaths.size() > 0) {
            String commandLine = "-mode,nway,-output," + outputPath + ","
                    + prefix + "upstream/Marlin/Marlin/" + mergedFile + "+upstream,";
            String title =3+ " way merge: " + mergedFile + " file. 'upstream' repo merge with fork '";
            for (int i = 0; i < inputFilePaths.size(); i++) {
                String forkName =inputFilePaths.get(i).split("\\+")[1];
                commandLine += prefix + inputFilePaths.get(i).split("\\+")[0] + mergedFile + "+" + forkName;
                title += inputFilePaths.get(i).split("/")[0] + "' ";
                commandLine += ",";
                commandLine +=upstreamOldPath+mergedFile+"+"+fork+"Upstream";


            }
            String[] arg = commandLine.split(",");

            try {
                long start = System.currentTimeMillis();
                Main.main(arg);
                long end = System.currentTimeMillis();

                long runTime = end - start;

                File file = new File("testcpp/mergedResult/runTime.txt");

                // if file doesnt exists, then create it
                if (!file.exists()) {
                    file.createNewFile();
                }
                FileWriter fw = new FileWriter(file.getAbsoluteFile(), true);
                BufferedWriter bw = new BufferedWriter(fw);
                bw.write(title + "\n");
                bw.write(String.valueOf(runTime) + "\n");
                bw.close();


            } catch (IOException e) {
                e.printStackTrace();
            } catch (ParseException e) {
                e.printStackTrace();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }



            try {
                result = readResult(outputPath + suffix).replace("\n", "").replace(" ", "").replace("\t", "");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return  result;
    }