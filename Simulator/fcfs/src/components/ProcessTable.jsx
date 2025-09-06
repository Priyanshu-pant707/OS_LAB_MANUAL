import React from "react";

export default function ProcessTable({ processes }) {
  return (
    <table className="w-full  border-collapse border border-gray-600 text-center">
      <thead>
        <tr className="bg-gray-700 ">
          <th className="border  border-gray-600 p-2">PID</th>
          <th className="border border-gray-600 p-2">AT</th>
          <th className="border border-gray-600 p-2">BT</th>
        </tr>
      </thead>
      <tbody>
        {processes.map((p, i) => (
          <tr key={i}>
            <td className="border text-black  border-gray-600 p-2">{p.pid}</td>
            <td className="border text-white border-gray-600 p-2">{p.at}</td>
            <td className="border text-black  border-gray-600 p-2">{p.bt}</td>
          </tr>
        ))}
      </tbody>
    </table>
  );
}
