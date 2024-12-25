import React, { useEffect, useRef } from 'react';
import L from 'leaflet';
import 'leaflet/dist/leaflet.css';
import 'leaflet-rotatedmarker'

declare module 'leaflet' {
  interface MarkerOptions {
    rotationAngle?: number;
    rotationOrigin?: string;
  }
}

// Define a custom marker icon
const customIcon = new L.Icon({
  iconUrl: 'https://icones.pro/wp-content/uploads/2021/08/icone-d-avion-jaune.png', // URL to your custom marker image
  iconSize: [50, 50], // Size of the icon
  iconAnchor: [22, 38], // Point of the icon that corresponds to the marker's location
  popupAnchor: [-3, -76], // Point from which the popup should open relative to the iconAnchor
});

interface MapPosition {
  lat: number,
  lng: number,
  yaw: number
}

const MapComponent: React.FC<MapPosition> = ({ lat, lng, yaw }) => {
  const mapRef = useRef<L.Map | null>(null);

  useEffect(() => {
    if (mapRef.current !== null) return;

    const map = L.map('map').setView([lat, lng], 15);
    mapRef.current = map;

    // Use custom tile layer (e.g., Stamen Terrain)
    L.tileLayer('https://tiles.stadiamaps.com/tiles/alidade_smooth_dark/{z}/{x}/{y}{r}.png', {
      minZoom: 0,
      maxZoom: 20,
      attribution: '&copy; <a href="https://www.stadiamaps.com/" target="_blank">Stadia Maps</a> &copy; <a href="https://openmaptiles.org/" target="_blank">OpenMapTiles</a> &copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors',
    }).addTo(map);

    // Add a marker with the custom icon
    L.marker([lat, lng], { icon: customIcon, rotationAngle: yaw }).addTo(map)
      .bindPopup('Custom Marker at Location')
      .openPopup();

    return () => {
      if (mapRef.current !== null) {
        mapRef.current.remove();
        mapRef.current = null;
      }
    };  
  }, [lat, lng, yaw]);

  return <div id="map" style={{ height: '100vh', width: '100%' }}></div>;
};

export default MapComponent;
