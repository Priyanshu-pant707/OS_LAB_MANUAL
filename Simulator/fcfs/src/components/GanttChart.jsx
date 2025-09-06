import React from "react";

export default function GanttChart({ result }) {
  if (result.length === 0) return null;

  return (
    <div className="flex mt-6">
      {result.map((p, i) => (
        <div
          key={i}
          className="border text-center bg-blue-500 text-white"
          style={{ width: `${p.bt * 50}px` }}
        >
          <p>{p.pid}</p>
          <p>{p.ct}</p>
        </div>
      ))}
    </div>
  );
}
