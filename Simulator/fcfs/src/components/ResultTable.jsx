import React from "react";

export default function ResultTable({ result }) {
  if (result.length === 0) return null;

  let avgTAT =
    result.reduce((sum, p) => sum + p.tat, 0) / result.length;
  let avgWT =
    result.reduce((sum, p) => sum + p.wt, 0) / result.length;

  return (
    <div className="mt-6">
      <table className="w-full border-collapse border border-gray-600 text-center">
        <thead>
          <tr className="bg-gray-700">
            <th className="border border-gray-600 p-2">PID</th>
            <th className="border border-gray-600 p-2">AT</th>
            <th className="border border-gray-600 p-2">BT</th>
            <th className="border border-gray-600 p-2">CT</th>
            <th className="border border-gray-600 p-2">TAT</th>
            <th className="border border-gray-600 p-2">WT</th>
          </tr>
        </thead>
        <tbody>
          {result.map((p, i) => (
            <tr key={i}>
              <td className="border border-gray-600 p-2">{p.pid}</td>
              <td className="border border-gray-600 p-2">{p.at}</td>
              <td className="border border-gray-600 p-2">{p.bt}</td>
              <td className="border border-gray-600 p-2">{p.ct}</td>
              <td className="border border-gray-600 p-2">{p.tat}</td>
              <td className="border border-gray-600 p-2">{p.wt}</td>
            </tr>
          ))}
        </tbody>
      </table>

      <div className="mt-4">
        <p>Average TAT: {avgTAT.toFixed(2)}</p>
        <p>Average WT: {avgWT.toFixed(2)}</p>
      </div>
    </div>
  );
}
