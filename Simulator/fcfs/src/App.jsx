import React, { useState } from "react";
import ProcessForm from "./components/ProcessForm.jsx";
import ProcessTable from "./components/ProcessTable.jsx";
import ResultTable from "./components/ResultTable.jsx";
import GanttChart from "./components/GanttChart.jsx";
import { calculateFCFS } from "./utils";
import './App.css'
function App() {
  const [processes, setProcesses] = useState([]);
  const [result, setResult] = useState([]);

  const addProcess = (p) => {
    setProcesses([...processes, p]);
  };

  const runFCFS = () => {
    setResult(calculateFCFS(processes));
  };

  return (
    <div className="main">

      <div className="name">
        <p>PriyanshuPant</p>
        <p>PriyanshuPant</p>
        <p>PriyanshuPant</p>
        <p>PriyanshuPant</p>
        <p>PriyanshuPant</p>
      </div>
      <div className="p-8 max-w-4xl mx-auto">
        <h1 className="text-5xl  text-red-800 font-bold mb-4 text-center">
          FCFS Scheduling Simulator
        </h1>

        <ProcessForm onAdd={addProcess} />
        <ProcessTable processes={processes} />

        <button
          className="mt-4 px-4 py-2 text-black font-bold bg-yellow-500 rounded hover:bg-yellow-600"
          onClick={runFCFS}
        >
          Run FCFS
        </button>

        <ResultTable result={result} />
        <GanttChart result={result} />
      </div>
    </div>
  );
}

export default App;
