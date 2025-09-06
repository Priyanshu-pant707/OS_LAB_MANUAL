import React, { useState } from "react";

export default function ProcessForm({ onAdd }) {
  const [pid, setPid] = useState("");
  const [at, setAt] = useState("");
  const [bt, setBt] = useState("");

  const handleAdd = () => {
    if (!pid || at === "" || bt === "") return;
    onAdd({ pid, at: Number(at), bt: Number(bt) });
    setPid("");
    setAt("");
    setBt("");
  };

  return (
    <div className="flex gap-2 my-4">
      <input
        className="p-2 rounded bg-red-900 text-white"
        placeholder="PID"
        value={pid}
        onChange={(e) => setPid(e.target.value)}
      />
      <input
        className="p-2 rounded bg-red-900 text-white"
        type="number"
        placeholder="Arrival Time"
        value={at}
        onChange={(e) => setAt(e.target.value)}
      />
      <input
        className="p-2 rounded bg-red-900 text-white"
        type="number"
        placeholder="Burst Time"
        value={bt}
        onChange={(e) => setBt(e.target.value)}
      />
      <button
        className="px-4 py-2 text-black font-bold bg-yellow-500 rounded hover:bg-yellow-600"
        onClick={handleAdd}
      >
        Add
      </button>
    </div>
  );
}
